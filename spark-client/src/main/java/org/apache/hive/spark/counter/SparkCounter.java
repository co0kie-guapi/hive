package org.apache.hive.spark.counter;

import  java.io.Serializable;
import  org.apache.spark.api.java.JavaSparkContext;
//   org.apache.spark.Accumulator已被删除，由以下类代替
import  org.apache.spark.util.LongAccumulator;
//  org.apache.spark.AccumulatorParam已被删除，一并删除它的实现类

public  class  SparkCounter  implements  Serializable  {
  private  String  name;

  private  String  displayName;

  private  LongAccumulator  accumulator;

  private  long  accumValue;

  public  SparkCounter()  {}

  private  SparkCounter(String  name,  String  displayName,  long  value)  {
    this.name  =  name;
    this.displayName  =  displayName;
    this.accumValue  =  value;
  }

  public  SparkCounter(String  name,  String  displayName,  String  groupName,  long  initValue,  JavaSparkContext  sparkContext)  {
    this.name  =  name;
    this.displayName  =  displayName;
    String  accumulatorName  =  groupName  +  "_"  +  name;
    // 修改累加器的获取方式
    this.accumulator  =  JavaSparkContext.toSparkContext(sparkContext).longAccumulator(accumulatorName);
    // 添加参数值
    this.accumulator.setValue(initValue);
  }

  public  long  getValue()  {
    if  (this.accumulator  !=  null) {
      return this.accumulator.value().longValue();
    }
    return  this.accumValue;
  }

  public  void  increment(long  incr)  {
    this.accumulator.add(incr);
  }

  public  String  getName()  {
    return  this.name;
  }

  public  String  getDisplayName()  {
    return  this.displayName;
  }

  public  void  setDisplayName(String  displayName)  {
    this.displayName  =  displayName;
  }

  SparkCounter  snapshot()  {
    return  new  SparkCounter(this.name,  this.displayName,  this.accumulator.value().longValue());
  }
}

package snake

import scala.collection.immutable.StringOps


object SnakePrint {

  def generate_input(dimension:Int):List[List[Int]] = {
    
    val input = for (ele<-List.range(0, dimension, 1)) yield List.range(ele*dimension, ele*dimension+dimension,1)
	val sops = new StringOps("%5d")
   	val sb = new StringBuilder();
    input.foreach(xs=> {
      sb.clear();
      val row = for(x<-xs) yield sops.format(x)
      println(row.addString(sb))
    })
    
    
    input
  }
  
  def snake_print(input: List[List[Int]]): Unit = input.length match {
    case 0 => ()
    case 1 => println(input.head.head)
    case 2 => {
    	printf("%5d\n",input.head.head)
    	printf("%5d\n",input.head.tail.head)
    	printf("%5d\n",input.tail.head.tail.head)      
    	printf("%5d\n", input.tail.head.head)
    }
    case _ => {
    	 val sops = new StringOps("%5d")
    	 val sb = new StringBuilder();
    	// top row
    	 val top = for(ele<-input.head.dropRight(1)) yield sops.format(ele)
    	 println(top.addString(sb))
    	 
    	 // right column
    	 val right = for ( ele<-input.dropRight(1)) yield sops.format(ele.takeRight(1).head)
    	 sb.clear();
    	 println(right.addString(sb))
    	 
    	 // bottom
    	 val bottom = for ( ele<-input.takeRight(1).head.drop(1).reverse) yield sops.format(ele)
    	 sb.clear()
    	 println(bottom.addString(sb))
    	 
    	 // left column
    	 val left = for (ele<-input.drop(1).reverse) yield sops.format(ele.head)
    	 sb.clear()
    	 println(left.addString(sb))
    	 
    	 var stripped = input.drop(1).dropRight(1) // stripped top and bottom row
    	 stripped = for ( ele<-stripped) yield ele.drop(1).dropRight(1)
    	 
    	 snake_print(stripped)
    }
	
  }
  
  def main(args:Array[String]): Unit = {
    
    val input = generate_input(10)
    println
    snake_print(input)
  }
}
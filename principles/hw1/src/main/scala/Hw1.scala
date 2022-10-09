sealed trait IntList
case object Nil extends IntList
case class Cons(v: Int, t: IntList) extends IntList

sealed trait BTree
case object Leaf extends BTree
case class IntNode(v: Int, left: BTree, right: BTree)
extends BTree

sealed trait Formula
case object True extends Formula
case object False extends Formula
case class Not(f: Formula) extends Formula
case class Andalso(left: Formula, right: Formula) extends Formula
case class Orelse(left: Formula, right: Formula)  extends Formula
case class Implies(left: Formula, right: Formula) extends Formula

object Hw1 extends App {

  println("Hw1!")

  def fibo(n: Int): Int = {
    // Implementation runs up to n-1, had to manually set to n+1
  fibonachi(n+1)

}
  def fibonachi(n: Int): Int = {
    if(n >= 2) return fibonachi(n-2)+fibonachi(n-1)
    return n
  }

  def sum(f: Int=>Int, n: Int): Int = {
    if(n<0) 0 
    else f(n) + sum(f, n-1) 
  }


  def foldRight(init: Int, ftn: (Int, Int)=>Int, list: IntList): Int = {
    if(list.isInstanceOf[Cons]) {
    val c = list.asInstanceOf[Cons]
    ftn(foldRight(init, ftn, c.t), c.v)
  }
    else  init
  }
  
  def filter(f: Int => Boolean, list: IntList): IntList =  {
    if(list.isInstanceOf[Cons]) {
    val c = list.asInstanceOf[Cons]
    if (f(c.v)) Cons(c.v, filter(f, c.t)) else  filter(f, c.t)
  }
    else  Nil
  }

  def iter[A](f: A => A, n: Int): A => A = {
    if (n<=1) f 
    else f compose iter(f,n-1)
  }
  
  def insert(t: BTree, a: Int): BTree = {
    if(t.isInstanceOf[IntNode]) {
    val c = t.asInstanceOf[IntNode]
    if (c.v ==a) return IntNode(a,c.left,c.right)
    else if(c.v<a) return IntNode(c.v,c.left,insert(c.right,a))
    return IntNode(c.v,insert(c.left,a),c.right)
  }
    return  IntNode(a, Leaf, Leaf)
  }
    

  
  def eval(f: Formula): Boolean = f match{
    case Andalso(a, b)=>eval(a)&&eval(b)
    case Orelse(a,b)=>eval(a)||eval(b)
    case Implies(a,b)=>(!eval(a))||eval(b)  
    case Not(f)=>(!eval(f))
    case True => true
    case False=>false
  }

}
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

  def fibo(n: Int): Int = 1

  def sum(f: Int=>Int, n: Int): Int = 1

  def foldRight(init: Int, ftn: (Int, Int)=>Int, list: IntList): Int = 1

  def filter(f: Int => Boolean, list: IntList): IntList = Nil

  def iter[A](f: A => A, n: Int): A => A = (x: A) => x
  
  def insert(t: BTree, a: Int): BTree = Leaf

  def eval(f: Formula): Boolean = false

}
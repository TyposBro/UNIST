class Hw1Test extends org.scalatest.funsuite.AnyFunSuite {
  test("Hw1.fibo") {
    assert(Hw1.fibo(1) === 1)
    assert(Hw1.fibo(9) === 55)
    assert(Hw1.fibo(10) === 89)
  }

  test("Hw1.sum") {
    def constant(x: Int) = x
    def square(x: Int) = x * x
    assert(Hw1.sum(constant,10) === 55)
    assert(Hw1.sum(square,2) === 5)
  }

  test("Hw1.foldRight") {
    assert(Hw1.foldRight(100, (x: Int, y:Int) => x % y, Cons(5,Cons(3,Nil))) === 1)
    assert(Hw1.foldRight(100, (x: Int, y:Int) => x % y, Cons(3,Cons(5,Nil))) === 0)
  }

  test("Hw1.filter") {
    assert(Hw1.filter((x: Int) => x % 3 == 0, Cons(5,Cons(3,Cons(6,Nil)))) === Cons(3,Cons(6,Nil)))
    assert(Hw1.filter((x: Int) => x % 5 == 0, Cons(5,Cons(3,Cons(6,Nil)))) === Cons(5,Nil))
  }

  test("Hw1.iter") {
    def constant(x: Int) = x
    def square(x: Int) = x * x
    assert(Hw1.iter[Int](constant, 10)(10) === 10)
    assert(Hw1.iter[Int](square, 3)(2) === 256)
  }

  test("Hw1.insert") {
    val step_0 = IntNode(10,IntNode(9,IntNode(8,Leaf,Leaf),Leaf),Leaf)
    val step_1 = Hw1.insert(step_0, 11)
    val step_2 = Hw1.insert(step_1, 12)
    assert(step_1 === IntNode(10,IntNode(9,IntNode(8,Leaf,Leaf),Leaf),IntNode(11,Leaf,Leaf)))
    assert(step_2 === IntNode(10,IntNode(9,IntNode(8,Leaf,Leaf),Leaf),IntNode(11,Leaf,IntNode(12,Leaf,Leaf))))
  }

  test("Hw1.eval") {
    assert(Hw1.eval(True) === true)
    assert(Hw1.eval(Andalso(Orelse(True,False),True)) === true)
  }


}

package tecnicheDiProgrammazione.stack

interface Stack <Value>{
    fun push(value : Value)
    fun pop () : Value?
    fun peek() : Value?
    fun isEmpty() : Boolean
    fun size() : Int


}
import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val t = sc.nextInt()
    
    repeat(t) {
        val n = sc.nextInt()
        val arr = LongArray(n)
        for(i in 0 until n) {
            arr[i] = sc.nextLong()
        }

        arr.sort()

        var score = 0
        var i = 0
        while(i < n - 1) {
            if(arr[i] == arr[i + 1]) {
                i += 2;
                score++;
            } else {
                i++
            }
        }
        println(score)
    }
}
fun levenshteinDistance(s: CharSequence, t: CharSequence,
                charScore: (Char, Char) -> Int = { c1, c2 -> if (c1 == c2) 0 else 1 }): Int {
    return when {
        s == t -> 0
        s.isEmpty() -> t.length
        t.isEmpty() -> s.length
        else -> {
            val initRow: List<Int> = (0 .. t.length).map { it }.toList()
            return (0 until s.length).fold(initRow, { prev, u ->
                (0 until t.length).fold(mutableListOf(u + 1), { row, v ->
                    row.add(minOf(row.last() + 1,
                            prev[v + 1] + 1,
                            prev[v] + charScore(s[u], t[v])))
                    row
                })
            }).last()
        }
    }
}

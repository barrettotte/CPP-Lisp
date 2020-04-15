; Step 3 - Testing def! and let*

; general test
(+ 1 2) ; -> 3
(/ (- (+ 5 (* 2 3)) 3) 4) ; -> 2

; check def! expression
(def! x 3) ; -> 3
(def! x 4) ; -> 4
(def! y (+ 1 7)) ; -> 8
y ; -> 8

; check case sensitivity
(def! mynum 111) ; -> 111
(def! MYNUM 222) ; -> 222

; check env lookup non-fatal error
;(abc 1 2 3) ; Could not find symbol 'abc'


; test let* expression
(let* (z 9) z) ; -> 9
(let* (x 9) x) ; -> 9
x ; -> 4

(let* (z (+ 2 3)) (+ 1 z)) ; -> 6
(let* (p (+ 2 3) q (+ 2 p)) (+ p q)) ; -> 12

(def! y(let* (z 7) z)) ; -> 7
y ; -> 7


; testing outer environment
(def! a 4) ; -> 4

(let* (q 9) q) ; -> 9
(let* (q 9) a) ; -> 4
(let* (z 2) (let* (q 9) a)) ; -> 4

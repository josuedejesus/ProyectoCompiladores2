declare void @exit(i32)
declare i32 @printf(i8*, ...)
define i32 @add(i32 %a, i32 %b) {
entry:


%t0 = add i32 %a, %b

ret i32 %t0

}

define i32 @addThree(i32 %a, i32 %b, i32 %c) {
entry:


%t1 = add i32 %a, %b


%t2 = add i32 %t1, %c

ret i32 %t2

}

define void @showResults() {
entry:

%t3 = call i32 @add(i32 5, i32 10)
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t3)



%t4 = call i32 @addThree(i32 5, i32 10, i32 15)
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t4)

ret void
}

define i32 @main() {
entry:
call void @showResults()


ret i32 0

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

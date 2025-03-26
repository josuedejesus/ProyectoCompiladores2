declare void @exit(i32)
declare i32 @printf(i8*, ...)
define i32 @factorial(i32 %n) {
entry:


%t0 = icmp sle i32 %n, 1

br i1 %t0, label %lb0, label %lb2
lb0:

ret i32 1

lb2:



%t1 = sub i32 %n, 1
%t2 = call i32 @factorial(i32 %t1)

%t3 = mul i32 %n, %t2

ret i32 %t3

br label %lb1
lb1:

ret i32 0
}

define i32 @main() {
entry:
%t4 = call i32 @factorial(i32 5)
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t4)


ret i32 0

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

declare void @exit(i32)
declare i32 @printf(i8*, ...)
define i32 @isPrime(i32 %num) {
entry:
%i = alloca i32, align 4



%t0 = icmp sle i32 %num, 1

br i1 %t0, label %lb0, label %lb1
lb0:

ret i32 0

br label %lb1
lb1:

store i32 2, i32* %i, align 4
br label %lb3
lb3:
%t1 = load i32, i32* %i, align 4


%t2 = icmp slt i32 %t1, %num

br i1 %t2, label %lb4, label %lb5
lb4:

%t3 = load i32, i32* %i, align 4

%t4 = srem i32 %num, %t3


%t5 = icmp eq i32 %t4, 0

br i1 %t5, label %lb6, label %lb7
lb6:

ret i32 0

br label %lb7
lb7:

%t6 = load i32, i32* %i, align 4


%t7 = add i32 %t6, 1
store i32 %t7, i32* %i, align 4
br label %lb3
lb5:


ret i32 1

}

define i32 @main() {
entry:
%t8 = call i32 @isPrime(i32 7)
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t8)


ret i32 0

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

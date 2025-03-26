declare void @exit(i32)
declare i32 @printf(i8*, ...)
define void @printFibonacci(i32 %count) {
entry:
%a = alloca i32, align 4
%b = alloca i32, align 4
%temp = alloca i32, align 4

%i = alloca i32, align 4

store i32 0, i32* %a, align 4
store i32 1, i32* %b, align 4
store i32 0, i32* %i, align 4
br label %lb0
lb0:
%t0 = load i32, i32* %i, align 4


%t1 = icmp slt i32 %t0, %count

br i1 %t1, label %lb1, label %lb2
lb1:
%t2 = load i32, i32* %a, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t2)

%t3 = load i32, i32* %a, align 4

%t4 = load i32, i32* %b, align 4

%t5 = add i32 %t3, %t4
store i32 %t5, i32* %temp, align 4
%t6 = load i32, i32* %b, align 4
store i32 %t6, i32* %a, align 4
%t7 = load i32, i32* %temp, align 4
store i32 %t7, i32* %b, align 4
%t8 = load i32, i32* %i, align 4


%t9 = add i32 %t8, 1
store i32 %t9, i32* %i, align 4
br label %lb0
lb2:

ret void
}

define i32 @main() {
entry:
call void @printFibonacci(i32 10)


ret i32 1

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

declare void @exit(i32)
declare i32 @printf(i8*, ...)
define i32 @findMax([5 x i32]* %arr) {
entry:
%max = alloca i32, align 4
%i = alloca i32, align 4


%t0 = getelementptr i32, i32* %arr, i32 0
%t1 = load i32, i32* %t0, align 4
store i32 %t1, i32* %max, align 4
store i32 1, i32* %i, align 4
br label %lb0
lb0:
%t2 = load i32, i32* %i, align 4


%t3 = icmp slt i32 %t2, 5

br i1 %t3, label %lb1, label %lb2
lb1:
%t4 = load i32, i32* %i, align 4

%t5 = getelementptr i32, i32* %arr, i32 %t4
%t6 = load i32, i32* %t5, align 4

%t7 = load i32, i32* %max, align 4

%t8 = icmp sgt i32 %t6, %t7

br i1 %t8, label %lb3, label %lb4
lb3:
%t9 = load i32, i32* %i, align 4

%t10 = getelementptr i32, i32* %arr, i32 %t9
%t11 = load i32, i32* %t10, align 4
store i32 %t11, i32* %max, align 4
br label %lb4
br label %lb4
lb4:

%t12 = load i32, i32* %i, align 4


%t13 = add i32 %t12, 1
store i32 %t13, i32* %i, align 4
br label %lb0
lb2:

%t14 = load i32, i32* %max, align 4

ret i32 %t14

}

define i32 @main() {
entry:
%array = alloca [5 x i32], align 4
%t15 = getelementptr i32, i32* %array, i32 0
store i32 11, i32* %t15

%t16 = getelementptr i32, i32* %array, i32 1
store i32 52, i32* %t16

%t17 = getelementptr i32, i32* %array, i32 2
store i32 34, i32* %t17

%t18 = getelementptr i32, i32* %array, i32 3
store i32 27, i32* %t18

%t19 = getelementptr i32, i32* %array, i32 4
store i32 39, i32* %t19

%t20 = call i32 @findMax([5 x i32]* %array)
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t20)


ret i32 1

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

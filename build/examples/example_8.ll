declare void @exit(i32)
declare i32 @printf(i8*, ...)
define void @bubbleSort([5 x i32]* %arr) {
entry:
%i = alloca i32, align 4
%j = alloca i32, align 4
%temp = alloca i32, align 4

store i32 0, i32* %i, align 4
br label %lb0
lb0:
%t0 = load i32, i32* %i, align 4


%t1 = icmp slt i32 %t0, 5

br i1 %t1, label %lb1, label %lb2
lb1:
store i32 0, i32* %j, align 4
br label %lb3
lb3:
%t2 = load i32, i32* %j, align 4


%t3 = load i32, i32* %i, align 4

%t4 = sub i32 5, %t3


%t5 = sub i32 %t4, 1

%t6 = icmp slt i32 %t2, %t5

br i1 %t6, label %lb4, label %lb5
lb4:
%t7 = load i32, i32* %j, align 4

%t8 = getelementptr i32, i32* %arr, i32 %t7
%t9 = load i32, i32* %t8, align 4

%t10 = load i32, i32* %j, align 4


%t11 = add i32 %t10, 1

%t12 = getelementptr i32, i32* %arr, i32 %t11
%t13 = load i32, i32* %t12, align 4

%t14 = icmp sgt i32 %t9, %t13

br i1 %t14, label %lb6, label %lb7
lb6:
%t15 = load i32, i32* %j, align 4

%t16 = getelementptr i32, i32* %arr, i32 %t15
%t17 = load i32, i32* %t16, align 4
store i32 %t17, i32* %temp, align 4
%t18 = load i32, i32* %j, align 4
%t19 = getelementptr i32, i32* %arr, i32 %t18
%t20 = load i32, i32* %j, align 4


%t21 = add i32 %t20, 1

%t22 = getelementptr i32, i32* %arr, i32 %t21
%t23 = load i32, i32* %t22, align 4
store i32 %t23, i32* %t19

%t24 = load i32, i32* %j, align 4


%t25 = add i32 %t24, 1
%t26 = getelementptr i32, i32* %arr, i32 %t25
%t27 = load i32, i32* %temp, align 4
store i32 %t27, i32* %t26

br label %lb7
br label %lb7
lb7:

%t28 = load i32, i32* %j, align 4


%t29 = add i32 %t28, 1
store i32 %t29, i32* %j, align 4
br label %lb3
lb5:

%t30 = load i32, i32* %i, align 4


%t31 = add i32 %t30, 1
store i32 %t31, i32* %i, align 4
br label %lb0
lb2:

ret void
}

define void @printArray([5 x i32]* %arr) {
entry:
%i = alloca i32, align 4

store i32 0, i32* %i, align 4
br label %lb9
lb9:
%t32 = load i32, i32* %i, align 4


%t33 = icmp slt i32 %t32, 5

br i1 %t33, label %lb10, label %lb11
lb10:
%t34 = load i32, i32* %i, align 4

%t35 = getelementptr i32, i32* %arr, i32 %t34
%t36 = load i32, i32* %t35, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t36)

%t37 = load i32, i32* %i, align 4


%t38 = add i32 %t37, 1
store i32 %t38, i32* %i, align 4
br label %lb9
lb11:

ret void
}

define i32 @main() {
entry:
%arr = alloca [5 x i32], align 4
%t39 = getelementptr i32, i32* %arr, i32 0
store i32 1, i32* %t39

%t40 = getelementptr i32, i32* %arr, i32 1
store i32 5, i32* %t40

%t41 = getelementptr i32, i32* %arr, i32 2
store i32 8, i32* %t41

%t42 = getelementptr i32, i32* %arr, i32 3
store i32 2, i32* %t42

%t43 = getelementptr i32, i32* %arr, i32 4
store i32 3, i32* %t43

call void @bubbleSort([5 x i32]* %arr)

call void @printArray([5 x i32]* %arr)


ret i32 0

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

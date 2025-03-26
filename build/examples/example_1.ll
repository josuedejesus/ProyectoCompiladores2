declare void @exit(i32)
declare i32 @printf(i8*, ...)
@matrix = global [9 x i32] zeroinitializer, align 4
define void @initializeMatrix() {
entry:
%i = alloca i32, align 4
%j = alloca i32, align 4

store i32 0, i32* %i, align 4
br label %lb0
lb0:
%t0 = load i32, i32* %i, align 4


%t1 = icmp slt i32 %t0, 3

br i1 %t1, label %lb1, label %lb2
lb1:
store i32 0, i32* %j, align 4
br label %lb3
lb3:
%t2 = load i32, i32* %j, align 4


%t3 = icmp slt i32 %t2, 3

br i1 %t3, label %lb4, label %lb5
lb4:
%t4 = load i32, i32* %i, align 4


%t5 = mul i32 %t4, 3

%t6 = load i32, i32* %j, align 4

%t7 = add i32 %t5, %t6
%t8 = getelementptr i32, i32* @matrix, i32 %t7
%t9 = load i32, i32* %i, align 4

%t10 = load i32, i32* %j, align 4

%t11 = mul i32 %t9, %t10
store i32 %t11, i32* %t8

%t12 = load i32, i32* %j, align 4


%t13 = add i32 %t12, 1
store i32 %t13, i32* %j, align 4
br label %lb3
lb5:

%t14 = load i32, i32* %i, align 4


%t15 = add i32 %t14, 1
store i32 %t15, i32* %i, align 4
br label %lb0
lb2:

ret void
}

define i32 @getSum() {
entry:
%total = alloca i32, align 4

%i = alloca i32, align 4
%j = alloca i32, align 4

store i32 0, i32* %total, align 4
store i32 0, i32* %i, align 4
br label %lb6
lb6:
%t16 = load i32, i32* %i, align 4


%t17 = icmp slt i32 %t16, 3

br i1 %t17, label %lb7, label %lb8
lb7:
store i32 0, i32* %j, align 4
br label %lb9
lb9:
%t18 = load i32, i32* %j, align 4


%t19 = icmp slt i32 %t18, 3

br i1 %t19, label %lb10, label %lb11
lb10:
%t20 = load i32, i32* %total, align 4

%t21 = load i32, i32* %i, align 4


%t22 = mul i32 %t21, 3

%t23 = load i32, i32* %j, align 4

%t24 = add i32 %t22, %t23

%t25 = getelementptr i32, i32* @matrix, i32 %t24
%t26 = load i32, i32* %t25, align 4

%t27 = add i32 %t20, %t26
store i32 %t27, i32* %total, align 4
%t28 = load i32, i32* %j, align 4


%t29 = add i32 %t28, 1
store i32 %t29, i32* %j, align 4
br label %lb9
lb11:

%t30 = load i32, i32* %i, align 4


%t31 = add i32 %t30, 1
store i32 %t31, i32* %i, align 4
br label %lb6
lb8:

%t32 = load i32, i32* %total, align 4

ret i32 %t32

}

define i32 @main() {
entry:
call void @initializeMatrix()

%t33 = call i32 @getSum()
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t33)


ret i32 0

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

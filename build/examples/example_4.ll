declare void @exit(i32)
declare i32 @printf(i8*, ...)
define void @incrementBy(i32* %x, i32 %y) {
entry:
%t0 = load i32, i32* %x, align 4


%t1 = add i32 %t0, %y
store i32 %t1, i32* %x, align 4

ret void
}

define void @applyIncrements() {
entry:
%base = alloca i32, align 4

%values = alloca [5 x i32], align 4
%i = alloca i32, align 4

store i32 0, i32* %base, align 4
store i32 0, i32* %i, align 4
br label %lb0
lb0:
%t2 = load i32, i32* %i, align 4


%t3 = icmp slt i32 %t2, 5

br i1 %t3, label %lb1, label %lb2
lb1:

%t4 = load i32, i32* %i, align 4
call void @incrementBy(i32* %base, i32 %t4)

%t5 = load i32, i32* %i, align 4
%t6 = getelementptr i32, i32* %values, i32 %t5
%t7 = load i32, i32* %base, align 4

%t8 = load i32, i32* %i, align 4

%t9 = add i32 %t7, %t8
store i32 %t9, i32* %t6

%t10 = load i32, i32* %i, align 4


%t11 = add i32 %t10, 1
store i32 %t11, i32* %i, align 4
br label %lb0
lb2:


%t12 = getelementptr i32, i32* %values, i32 0
%t13 = load i32, i32* %t12, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t13)


%t14 = getelementptr i32, i32* %values, i32 1
%t15 = load i32, i32* %t14, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t15)


%t16 = getelementptr i32, i32* %values, i32 2
%t17 = load i32, i32* %t16, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t17)


%t18 = getelementptr i32, i32* %values, i32 3
%t19 = load i32, i32* %t18, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t19)


%t20 = getelementptr i32, i32* %values, i32 4
%t21 = load i32, i32* %t20, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t21)

ret void
}

define i32 @main() {
entry:
call void @applyIncrements()


ret i32 0

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

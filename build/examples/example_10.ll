declare void @exit(i32)
declare i32 @printf(i8*, ...)
define i32 @square(i32 %x) {
entry:


%t0 = mul i32 %x, %x

ret i32 %t0

}

define i32 @calculateExpression(i32 %a, i32 %b, i32 %c) {
entry:
%t1 = call i32 @square(i32 %a)

%t2 = call i32 @square(i32 %b)

%t3 = add i32 %t1, %t2

%t4 = call i32 @square(i32 %c)

%t5 = add i32 %t3, %t4

ret i32 %t5

}

define void @displayResult() {
entry:
%result = alloca i32, align 4



%t6 = call i32 @calculateExpression(i32 2, i32 3, i32 4)
store i32 %t6, i32* %result, align 4
%t7 = load i32, i32* %result, align 4
call i32 (i8*, ...) @printf(i8* @.fmt, i32 %t7)

ret void
}

define i32 @main() {
entry:
call void @displayResult()


ret i32 1

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1

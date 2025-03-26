declare void @exit(i32)
declare i32 @printf(i8*, ...)
define void @analyze(i32 %x, i32 %y) {
entry:


%t0 = icmp sgt i32 %x, 0



%t1 = icmp sgt i32 %y, 0

%t4 = and i1 %t0, %t1

br i1 %t4, label %lb0, label %lb2
lb0:
call i32 (i8*, ...) @printf(i8* @.tx0)
br label %lb1
lb2:


%t5 = icmp slt i32 %x, 0



%t6 = icmp slt i32 %y, 0

%t9 = or i1 %t5, %t6

br i1 %t9, label %lb3, label %lb5
lb3:
call i32 (i8*, ...) @printf(i8* @.tx1)
br label %lb4
lb5:
call i32 (i8*, ...) @printf(i8* @.tx2)
br label %lb4
lb4:

br label %lb1
lb1:

ret void
}

define i32 @main() {
entry:

call void @analyze(i32 -20, i32 5)


ret i32 1

}
@.fmt = private constant [4 x i8] c"%d\0A\00", align 1
@.tx2 = private constant [46 x i8] c"Both numbers are zero or one of them is zero\0A\00", align 1
@.tx1 = private constant [33 x i8] c"At least one number is negative\0A\00", align 1
@.tx0 = private constant [27 x i8] c"Both numbers are positive\0A\00", align 1

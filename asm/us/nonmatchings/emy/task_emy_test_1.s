.syntax unified
	.align 2, 0
	.global task_emy_test_1
	.thumb
	.thumb_func
	.type task_emy_test_1, %function
task_emy_test_1: @ 0803EFE4
	push {r4, lr}
	adds r4, r0, #0x0
	bl _0800CBDC
	adds r0, r4, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
.syntax divided

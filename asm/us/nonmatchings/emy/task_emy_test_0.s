.syntax unified
	.align 2, 0
	.global task_emy_test_0
	.thumb
	.thumb_func
	.type task_emy_test_0, %function
task_emy_test_0: @ 0803EFA8
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _0803EFD4 @ =0x0813E834
	bl func_0800C778
	adds r0, r4, #0x0
	adds r0, #0x6A
	ldr r1, _0803EFD8 @ =0x00000BB8
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strh r1, [r0, #0x00]
	ldr r0, [r4, #0x70]
	ldr r1, [r4, #0x74]
	ldr r2, _0803EFDC @ =0x00001000
	ldr r3, _0803EFE0 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x70]
	str r1, [r4, #0x74]
	pop {r4}
	pop {r0}
	bx r0
_0803EFD4: .4byte 0x0813E834
_0803EFD8: .4byte 0x00000BB8
_0803EFDC: .4byte 0x00001000
_0803EFE0: .4byte 0x00000000
.syntax divided

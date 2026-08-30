.syntax unified
	.align 2, 0
	.global func_08004BD8
	.thumb
	.thumb_func
	.type func_08004BD8, %function
func_08004BD8: @ 08004BD8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0x0
	adds r0, r1, #0x0
	adds r5, r2, #0x0
	lsls r0, r0, #0x10
	lsls r5, r5, #0x10
	lsrs r0, r0, #0x18
	ldrb r1, [r6, #0x08]
	mov r8, r1
	bl func_0811D684
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsrs r5, r5, #0x18
	ldrb r1, [r6, #0x09]
	adds r0, r5, #0x0
	bl func_0811D684
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	muls r1, r0
	adds r0, r1, #0x0
	adds r0, r0, r4
	ldr r1, [r6, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided

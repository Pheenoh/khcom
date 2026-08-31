.syntax unified
	.align 2, 0
	.global func_0801B8A8
	.thumb
	.thumb_func
	.type func_0801B8A8, %function
func_0801B8A8: @ 0801B8A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	adds r1, r2, #0x0
	adds r6, r3, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	movs r2, #0x00
	ldsh r0, [r6, r2]
	lsrs r2, r1, #0x10
	mov r8, r2
	asrs r1, r1, #0x10
	bl __divsi3
	strh r4, [r5, #0x12]
	movs r4, #0x00
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bge _0801B8F6
	adds r7, r0, #0x0
_0801B8D8:
	ldr r0, _0801B910 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, _0801B914 @ =0x09EDAF18
	adds r2, r5, #0x0
	bl TaskCreate
	lsls r0, r4, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	blt _0801B8D8
_0801B8F6:
	movs r2, #0x00
	ldsh r0, [r6, r2]
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	bl __modsi3
	strh r0, [r6, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801B910: .4byte 0x02039B84
_0801B914: .4byte 0x09EDAF18
.syntax divided

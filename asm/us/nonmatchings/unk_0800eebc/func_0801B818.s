.syntax unified
	.align 2, 0
	.global func_0801B818
	.thumb
	.thumb_func
	.type func_0801B818, %function
func_0801B818: @ 0801B818
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	adds r1, r2, #0x0
	adds r6, r3, #0x0
	ldr r0, [sp, #0x01C]
	mov r8, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	movs r2, #0x00
	ldsh r0, [r6, r2]
	lsrs r2, r1, #0x10
	mov r9, r2
	asrs r1, r1, #0x10
	bl __divsi3
	strh r4, [r5, #0x12]
	movs r4, #0x00
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	bge _0801B888
	adds r7, r0, #0x0
_0801B84E:
	ldr r0, _0801B870 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, _0801B874 @ =0x09EDAF18
	adds r2, r5, #0x0
	bl TaskCreate
	mov r1, r8
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	ble _0801B878
	movs r0, #0x01
	b _0801B89A
_0801B870: .4byte 0x02039B84
_0801B874: .4byte 0x09EDAF18
_0801B878:
	lsls r0, r4, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	blt _0801B84E
_0801B888:
	movs r1, #0x00
	ldsh r0, [r6, r1]
	mov r2, r9
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	bl __modsi3
	strh r0, [r6, #0x00]
	movs r0, #0x00
_0801B89A:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

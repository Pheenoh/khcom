.syntax unified
	.align 2, 0
	.global func_0806BA0C
	.thumb
	.thumb_func
	.type func_0806BA0C, %function
func_0806BA0C: @ 0806BA0C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r1
	movs r7, #0x00
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x00
	blt _0806BA66
	movs r5, #0xFA
	lsls r5, r5, #0x02
	movs r1, #0x00
	mov r8, r0
_0806BA28:
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	mov r0, r9
	adds r6, r0, r4
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	mov r0, r8
	adds r1, r5, #0x0
	bl func_0811D5EC
	subs r0, r0, r7
	strb r0, [r6, #0x00]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	adds r1, r1, r0
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r7, r0, #0x10
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl func_0811D5EC
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x03
	ble _0806BA28
_0806BA66:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

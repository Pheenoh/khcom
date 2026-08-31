.syntax unified
	.align 2, 0
	.global func_08096C38
	.thumb
	.thumb_func
	.type func_08096C38, %function
func_08096C38: @ 08096C38
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	movs r6, #0x00
	bl func_08093B38
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x62
	bhi _08096CBA
	cmp r6, r8
	bge _08096CBC
_08096C5C:
	lsls r0, r6, #0x03
	mov r1, r9
	adds r4, r0, r1
_08096C62:
	ldr r7, [r4, #0x00]
	ldrh r5, [r4, #0x04]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r4, [r4, #0x06]
	cmp r1, r4
	bhi _08096CA6
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, r0, r7
	ldrh r4, [r0, #0x00]
	adds r0, r4, #0x0
	bl func_08093B08
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x59
	bls _08096CB6
_08096CA6:
	adds r6, #0x01
	cmp r6, r8
	blt _08096C5C
	mov r4, r9
	movs r6, #0x00
	cmp r6, r8
	blt _08096C62
	b _08096CBC
_08096CB6:
	adds r0, r4, #0x0
	b _08096CBC
_08096CBA:
	ldr r0, _08096CC8 @ =0x0000FFFF
_08096CBC:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08096CC8: .4byte 0x0000FFFF
.syntax divided

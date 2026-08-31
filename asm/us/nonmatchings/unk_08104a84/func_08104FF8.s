.syntax unified
	.align 2, 0
	.global func_08104FF8
	.thumb
	.thumb_func
	.type func_08104FF8, %function
func_08104FF8: @ 08104FF8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	movs r1, #0x00
	ldr r0, _08105044 @ =0x02035C30
	mov r9, r0
	movs r2, #0x03
	mov r8, r2
_0810500C:
	lsls r1, r1, #0x10
	asrs r5, r1, #0x10
	lsls r4, r5, #0x01
	mov r2, r9
	adds r0, r4, r2
	movs r2, #0x00
	ldsh r6, [r0, r2]
	adds r7, r1, #0x0
	cmp r6, #0x00
	beq _0810504C
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	adds r0, r4, r5
	lsls r0, r0, #0x05
	movs r1, #0xE0
	lsls r1, r1, #0x01
	adds r0, r0, r1
	adds r2, r2, r0
	mov r0, r8
	str r0, [sp, #0x000]
	adds r0, r6, #0x0
	ldr r1, _08105048 @ =0x09A1DE3C
	movs r3, #0x20
	bl func_08101588
	b _0810506E
_08105044: .4byte 0x02035C30
_08105048: .4byte 0x09A1DE3C
_0810504C:
	movs r0, #0x00
	bl GetBgCharBase
	adds r2, r0, #0x0
	adds r0, r4, r5
	lsls r0, r0, #0x05
	movs r1, #0xE0
	lsls r1, r1, #0x01
	adds r0, r0, r1
	adds r2, r2, r0
	mov r0, r8
	str r0, [sp, #0x000]
	movs r0, #0x00
	ldr r1, _0810508C @ =0x09A1DE1C
	movs r3, #0x20
	bl func_08101588
_0810506E:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r7, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _0810500C
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810508C: .4byte 0x09A1DE1C
.syntax divided

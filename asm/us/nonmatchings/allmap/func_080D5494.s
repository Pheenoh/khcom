.syntax unified
	.align 2, 0
	.global func_080D5494
	.thumb
	.thumb_func
	.type func_080D5494, %function
func_080D5494: @ 080D5494
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	movs r5, #0x00
	ldr r7, _080D54E0 @ =0x0203C4B4
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
_080D54A6:
	ldr r0, [r7, #0x00]
	lsls r4, r5, #0x02
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D54E4
	ldr r0, [r7, #0x00]
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x04]
	adds r0, r1, #0x0
	adds r0, #0x8C
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r8, r0
	bne _080D54E4
	lsrs r0, r6, #0x10
	adds r1, #0x8E
	movs r2, #0x00
	ldsh r1, [r1, r2]
	cmp r0, r1
	bne _080D54E4
	adds r0, r5, #0x0
	b _080D54F0
_080D54E0: .4byte 0x0203C4B4
_080D54E4:
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x1F
	bls _080D54A6
	movs r0, #0xFF
_080D54F0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

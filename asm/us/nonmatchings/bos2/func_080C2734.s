.syntax unified
	.align 2, 0
	.global func_080C2734
	.thumb
	.thumb_func
	.type func_080C2734, %function
func_080C2734: @ 080C2734
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	movs r1, #0x88
	lsls r1, r1, #0x01
	adds r0, r0, r1
	movs r2, #0x2C
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	ble _080C2822
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1E
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080C2768
	adds r0, r4, #0x0
	adds r0, #0x58
	ldr r1, _080C27D8 @ =0x09EF2EA8
	ldr r2, [r4, #0x00]
	bl func_08000E14
_080C2768:
	ldr r2, [r4, #0x00]
	movs r6, #0xD6
	lsls r6, r6, #0x02
	adds r3, r2, r6
	ldrh r1, [r3, #0x00]
	movs r0, #0x20
	ands r0, r1
	adds r1, r2, #0x0
	ldr r5, _080C27DC @ =0x02039B84
	cmp r0, #0x00
	bne _080C2790
	ldr r0, [r5, #0x00]
	ldr r2, [r0, #0x7C]
	movs r0, #0xD7
	lsls r0, r0, #0x02
	adds r1, r1, r0
	ldr r0, [r2, #0x04]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x04]
_080C2790:
	adds r0, r4, #0x0
	adds r0, #0x70
	ldr r1, [r5, #0x00]
	movs r2, #0xE5
	lsls r2, r2, #0x01
	adds r2, r2, r1
	mov r12, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x00
	ldsb r1, [r2, r1]
	cmp r0, r1
	beq _080C2818
	cmp r1, #0x00
	ble _080C27F2
	ldr r1, [r4, #0x00]
	adds r1, r1, r6
	ldrh r2, [r1, #0x00]
	movs r0, #0x40
	orrs r0, r2
	strh r0, [r1, #0x00]
	mov r1, r12
	movs r0, #0x00
	ldsb r0, [r1, r0]
	cmp r0, #0x0E
	ble _080C27E0
	ldr r0, [r4, #0x00]
	movs r2, #0xD7
	lsls r2, r2, #0x02
	adds r0, r0, r2
	movs r1, #0xC0
	lsls r1, r1, #0x01
	str r1, [r0, #0x00]
	b _080C2822
	.byte 0x00, 0x00
_080C27D8: .4byte 0x09EF2EA8
_080C27DC: .4byte 0x02039B84
_080C27E0:
	ldr r4, [r4, #0x00]
	movs r0, #0xD7
	lsls r0, r0, #0x02
	adds r4, r4, r0
	mov r1, r12
	movs r0, #0x00
	ldsb r0, [r1, r0]
	lsls r0, r0, #0x08
	b _080C280E
_080C27F2:
	cmp r1, #0x00
	bge _080C2818
	ldrh r1, [r3, #0x00]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r3, #0x00]
	ldr r4, [r4, #0x00]
	movs r2, #0xD7
	lsls r2, r2, #0x02
	adds r4, r4, r2
	mov r1, r12
	movs r0, #0x00
	ldsb r0, [r1, r0]
	lsls r0, r0, #0x09
_080C280E:
	movs r1, #0x0A
	bl __divsi3
	str r0, [r4, #0x00]
	b _080C2822
_080C2818:
	ldrh r1, [r3, #0x00]
	movs r0, #0x41
	negs r0, r0
	ands r0, r1
	strh r0, [r3, #0x00]
_080C2822:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided

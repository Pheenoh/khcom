.syntax unified
	.align 2, 0
	.global func_080E8FB8
	.thumb
	.thumb_func
	.type func_080E8FB8, %function
func_080E8FB8: @ 080E8FB8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	adds r5, r3, #0x0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080E901C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080E9028
	bl func_080840E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080E9028
	ldr r0, _080E9020 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	bne _080E9028
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0x00
	bne _080E9028
	ldr r0, _080E9024 @ =0x0203C590
	ldrb r0, [r0, #0x06]
	bl func_080DEE18
	ldrb r0, [r0, #0x0C]
	cmp r0, #0x00
	beq _080E9028
	adds r0, r4, #0x0
	bl func_080E8E74
	cmp r0, #0x00
	beq _080E9028
	str r5, [sp, #0x000]
	movs r1, #0x00
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl func_080E8F50
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080E902A
_080E901C: .4byte 0x02039BB0
_080E9020: .4byte 0x0203C7AC
_080E9024: .4byte 0x0203C590
_080E9028:
	movs r0, #0x00
_080E902A:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

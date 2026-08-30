.syntax unified
	.align 2, 0
	.global func_08094CE4
	.thumb
	.thumb_func
	.type func_08094CE4, %function
func_08094CE4: @ 08094CE4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	bl func_08094CB0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08094D68
	adds r7, r6, #0x0
	adds r7, #0x6C
	ldrh r1, [r7, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08094D9C
	ldr r4, [r6, #0x18]
	ldr r5, [r6, #0x1C]
	ldr r0, [r4, #0x00]
	ldrh r1, [r4, #0x18]
	bl func_080026A4
	str r0, [r6, #0x08]
	ldr r0, [r4, #0x04]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x0C]
	ldr r0, [r5, #0x00]
	ldrh r1, [r5, #0x14]
	bl func_080026A4
	str r0, [r6, #0x10]
	ldr r0, [r5, #0x04]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x14]
	ldr r0, _08094D64 @ =0x0905EAE8
	movs r1, #0xF0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r6, #0x00]
	ldr r0, [r6, #0x0C]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r6, #0x14]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldrh r1, [r7, #0x00]
	movs r0, #0x01
	orrs r0, r1
	strh r0, [r7, #0x00]
	b _08094D9C
	.byte 0x00, 0x00
_08094D64: .4byte 0x0905EAE8
_08094D68:
	adds r4, r6, #0x0
	adds r4, #0x6C
	ldrh r1, [r4, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08094D9C
	ldr r0, [r6, #0x00]
	bl func_080028C0
	ldr r0, [r6, #0x08]
	bl func_080028C0
	ldr r0, [r6, #0x0C]
	bl func_08002C10
	ldr r0, [r6, #0x10]
	bl func_080028C0
	ldr r0, [r6, #0x14]
	bl func_08002C10
	ldrh r1, [r4, #0x00]
	ldr r0, _08094DA4 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r4, #0x00]
_08094D9C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08094DA4: .4byte 0x0000FFFE
.syntax divided

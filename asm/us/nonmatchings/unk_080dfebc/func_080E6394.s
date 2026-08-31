.syntax unified
	.align 2, 0
	.global func_080E6394
	.thumb
	.thumb_func
	.type func_080E6394, %function
func_080E6394: @ 080E6394
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	mov r12, r1
	adds r5, r6, #0x0
	adds r5, #0x08
	ldr r7, [r1, #0x00]
	str r7, [r6, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xCC
	ldr r0, [r1, #0x04]
	str r0, [r2, #0x00]
	movs r0, #0x00
	mov r8, r0
	mov r1, r8
	strh r1, [r6, #0x04]
	adds r2, #0x14
	movs r0, #0x1E
	strh r0, [r2, #0x00]
	adds r2, r5, #0x0
	mov r0, r12
	adds r0, #0x08
	ldm r0!, {r1, r3, r4}
	stm r2!, {r1, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	mov r2, r12
	ldrb r0, [r2, #0x18]
	strb r0, [r5, #0x14]
	ldr r0, [r2, #0x1C]
	str r0, [r5, #0x10]
	ldrh r0, [r7, #0x0A]
	strh r0, [r5, #0x1A]
	mov r3, r8
	strh r3, [r5, #0x34]
	movs r4, #0x01
	strh r4, [r5, #0x30]
	ldrh r1, [r7, #0x0C]
	adds r0, r6, #0x0
	adds r0, #0xC8
	strh r1, [r0, #0x00]
	ldrh r0, [r7, #0x0A]
	adds r1, r6, #0x0
	adds r1, #0xCA
	strh r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xD0
	strh r3, [r0, #0x00]
	adds r0, #0x02
	strh r3, [r0, #0x00]
	adds r1, #0x0A
	ldr r0, [r6, #0x08]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r5, #0x04]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r5, #0x08]
	str r0, [r1, #0x00]
	ldr r1, _080E6494 @ =0x02034F40
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _080E6498 @ =0x02034F41
	ldrb r0, [r7, #0x08]
	ldrb r2, [r1, #0x00]
	adds r0, r0, r2
	strb r0, [r1, #0x00]
	ldrh r0, [r7, #0x08]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl AllocObjTiles
	adds r1, r6, #0x0
	adds r1, #0xBC
	str r0, [r1, #0x00]
	ldr r0, [r7, #0x04]
	movs r1, #0x20
	bl LoadObjPalette
	adds r1, r6, #0x0
	adds r1, #0xC0
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xC4
	mov r3, r8
	str r3, [r0, #0x00]
	subs r0, #0x20
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	movs r0, #0xE4
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0x02
	bl TaskPoolInit
	ldrh r0, [r7, #0x14]
	ands r4, r0
	cmp r4, #0x00
	bne _080E646E
	ldr r1, _080E649C @ =0x09EDAF90
	mov r0, r8
	adds r2, r5, #0x0
	bl TaskCreate
_080E646E:
	ldrh r1, [r7, #0x14]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080E64A0
	ldrh r0, [r6, #0x04]
	movs r1, #0x02
	orrs r0, r1
	strh r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x48
	ldrh r2, [r7, #0x0C]
	ldrh r3, [r7, #0x0A]
	adds r0, r4, #0x0
	movs r1, #0x0B
	bl func_080122AC
	b _080E64B0
	.byte 0x00, 0x00
_080E6494: .4byte 0x02034F40
_080E6498: .4byte 0x02034F41
_080E649C: .4byte 0x09EDAF90
_080E64A0:
	adds r4, r6, #0x0
	adds r4, #0x48
	ldrh r2, [r7, #0x0C]
	ldrh r3, [r7, #0x0A]
	adds r0, r4, #0x0
	movs r1, #0x03
	bl func_080122AC
_080E64B0:
	ldr r1, [r5, #0x00]
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	adds r0, r6, #0x0
	bl _080E5CD4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided

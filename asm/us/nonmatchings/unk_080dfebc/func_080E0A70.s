.syntax unified
	.align 2, 0
	.global func_080E0A70
	.thumb
	.thumb_func
	.type func_080E0A70, %function
func_080E0A70: @ 080E0A70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	cmp r5, #0x00
	beq _080E0AEC
	ldrh r1, [r5, #0x00]
	movs r0, #0x0C
	ands r0, r1
	cmp r0, #0x00
	bne _080E0A8C
	strb r6, [r5, #0x04]
	b _080E0AEC
_080E0A8C:
	ldr r0, _080E0AF8 @ =0x02034F34
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x18]
	mov r8, r0
	lsls r4, r6, #0x02
	ldr r0, _080E0AFC @ =0x0984D32C
	adds r4, r4, r0
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r7, [r4, #0x03]
	adds r1, r7, #0x0
	bl __modsi3
	lsls r0, r0, #0x18
	movs r1, #0xE0
	lsls r1, r1, #0x13
	ands r1, r0
	lsrs r1, r1, #0x18
	ldrb r2, [r4, #0x01]
	adds r1, r1, r2
	lsls r1, r1, #0x02
	lsrs r0, r0, #0x1B
	ldrb r4, [r4, #0x02]
	adds r0, r0, r4
	lsls r0, r0, #0x06
	adds r1, r1, r0
	ldrh r3, [r5, #0x00]
	movs r0, #0x08
	ands r0, r3
	cmp r0, #0x00
	beq _080E0AE4
	lsls r2, r7, #0x02
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x04
	ands r0, r3
	cmp r0, #0x00
	beq _080E0AE4
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_080E0AE4:
	strb r6, [r5, #0x04]
	lsls r0, r1, #0x01
	add r0, r8
	str r0, [r5, #0x18]
_080E0AEC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E0AF8: .4byte 0x02034F34
_080E0AFC: .4byte 0x0984D32C
.syntax divided

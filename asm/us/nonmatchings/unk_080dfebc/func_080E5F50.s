.syntax unified
	.align 2, 0
	.global func_080E5F50
	.thumb
	.thumb_func
	.type func_080E5F50, %function
func_080E5F50: @ 080E5F50
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r0, #0x74
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080E5FAE
	ldr r0, _080E5F84 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x04
	ands r0, r1
	adds r5, r4, #0x0
	adds r5, #0x48
	cmp r0, #0x00
	bne _080E5F88
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E5F88
	adds r0, r4, #0x0
	bl func_080E5EAC
	b _080E5FAE
_080E5F84: .4byte 0x0203C7AC
_080E5F88:
	adds r0, r5, #0x0
	movs r1, #0x06
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E5FAE
	adds r1, r4, #0x0
	adds r1, #0x80
	ldr r0, [r4, #0x08]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r4, #0x08]
	adds r1, r4, #0x0
	adds r1, #0x84
	ldr r0, [r4, #0x0C]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r4, #0x0C]
_080E5FAE:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080E7FCC
	.thumb
	.thumb_func
	.type func_080E7FCC, %function
func_080E7FCC: @ 080E7FCC
	push {r4, r5, r6, lr}
	add sp, #-0x010
	ldr r0, _080E8040 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x0D]
	cmp r0, #0x06
	beq _080E7FDE
	cmp r0, #0x17
	bne _080E8038
_080E7FDE:
	ldr r4, _080E8044 @ =0x0984C1CC
	ldrb r1, [r4, #0x15]
	mov r0, sp
	bl func_080E7D64
	ldr r3, _080E8048 @ =0x02034F78
	ldrb r1, [r3, #0x00]
	ldr r0, _080E804C @ =0x0203C7B8
	ldr r2, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldrb r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	str r4, [r0, #0x14]
	ldrb r0, [r3, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	adds r1, #0x04
	mov r0, sp
	ldm r0!, {r2, r5, r6}
	stm r1!, {r2, r5, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _080E8050 @ =0x02034F7A
	ldrh r0, [r4, #0x08]
	lsrs r0, r0, #0x05
	ldrh r2, [r1, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldr r1, _080E8054 @ =0x02034F79
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
_080E8038:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080E8040: .4byte 0x0203C7AC
_080E8044: .4byte 0x0984C1CC
_080E8048: .4byte 0x02034F78
_080E804C: .4byte 0x0203C7B8
_080E8050: .4byte 0x02034F7A
_080E8054: .4byte 0x02034F79
.syntax divided

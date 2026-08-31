.syntax unified
	.align 2, 0
	.global func_080D2EB8
	.thumb
	.thumb_func
	.type func_080D2EB8, %function
func_080D2EB8: @ 080D2EB8
	push {r4, r5, r6, r7, lr}
	movs r5, #0x00
	ldr r7, _080D2EF8 @ =0x0203C4B4
	ldr r0, [r7, #0x00]
	ldrh r0, [r0, #0x30]
	cmp r5, r0
	bge _080D2F06
	adds r6, r7, #0x0
_080D2EC8:
	ldr r1, [r6, #0x00]
	lsls r4, r5, #0x03
	adds r2, r1, r4
	ldrh r0, [r2, #0x04]
	cmp r0, #0x3B
	bne _080D2EDE
	adds r0, r1, #0x0
	adds r0, #0x32
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D2EFC
_080D2EDE:
	ldrb r0, [r2, #0x06]
	cmp r0, #0x00
	beq _080D2EFC
	ldr r0, [r2, #0x00]
	bl func_080C76B0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D2EFC
	ldr r0, [r6, #0x00]
	adds r0, r0, r4
	ldrh r0, [r0, #0x04]
	b _080D2F08
_080D2EF8: .4byte 0x0203C4B4
_080D2EFC:
	adds r5, #0x01
	ldr r0, [r7, #0x00]
	ldrh r0, [r0, #0x30]
	cmp r5, r0
	blt _080D2EC8
_080D2F06:
	movs r0, #0xB4
_080D2F08:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x02, 0x49, 0x09, 0x68, 0x32, 0x31, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00, 0xB4, 0xC4
	.byte 0x03, 0x02
.syntax divided

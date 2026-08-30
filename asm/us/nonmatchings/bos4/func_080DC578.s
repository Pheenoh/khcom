.syntax unified
	.align 2, 0
	.global func_080DC578
	.thumb
	.thumb_func
	.type func_080DC578, %function
func_080DC578: @ 080DC578
	push {lr}
	bl func_080DC544
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DC59E
	bl func_080DC528
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DC59E
	ldr r0, _080DC5A4 @ =0x02034F0C
	ldr r0, [r0, #0x00]
	movs r1, #0xAF
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080DC5A8
_080DC59E:
	movs r0, #0x00
	b _080DC5AA
	.byte 0x00, 0x00
_080DC5A4: .4byte 0x02034F0C
_080DC5A8:
	movs r0, #0x01
_080DC5AA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

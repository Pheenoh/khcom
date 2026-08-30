.syntax unified
	.align 2, 0
	.global func_080C98B8
	.thumb
	.thumb_func
	.type func_080C98B8, %function
func_080C98B8: @ 080C98B8
	push {lr}
	adds r3, r0, #0x0
	ldr r0, _080C98F4 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080C9906
	ldr r1, _080C98F8 @ =0x0203C3E4
	ldrh r0, [r1, #0x00]
	ldr r2, _080C98FC @ =0x0203C3E0
	cmp r0, #0x00
	beq _080C98D4
	ldrh r0, [r2, #0x00]
	subs r0, #0x01
	strh r0, [r2, #0x00]
_080C98D4:
	ldrh r0, [r2, #0x00]
	cmp r0, #0x00
	bne _080C9906
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080C98EA
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080C9900
_080C98EA:
	adds r0, r3, #0x0
	movs r1, #0x17
	bl func_080C84E0
	b _080C9906
_080C98F4: .4byte 0x02034DAC
_080C98F8: .4byte 0x0203C3E4
_080C98FC: .4byte 0x0203C3E0
_080C9900:
	ldr r1, _080C990C @ =0x0000073B
	adds r0, r1, #0x0
	strh r0, [r2, #0x00]
_080C9906:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C990C: .4byte 0x0000073B
.syntax divided

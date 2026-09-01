.syntax unified
	.align 2, 0
	.global func_080C9DAC
	.thumb
	.thumb_func
	.type func_080C9DAC, %function
func_080C9DAC: @ 080C9DAC
	push {lr}
	ldr r0, _080C9DC8 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x0D
	beq _080C9E1E
	cmp r0, #0x02
	bne _080C9DD0
	ldr r0, _080C9DCC @ =0x02034DA8
	ldr r0, [r0, #0x00]
	adds r0, #0xF6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080C9E22
	b _080C9E1E
_080C9DC8: .4byte 0x02034DAC
_080C9DCC: .4byte 0x02034DA8
_080C9DD0:
	cmp r0, #0x15
	bne _080C9E22
	ldr r0, _080C9E00 @ =0x02034DA8
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C9E04
	adds r0, r1, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080C9E1E
	adds r0, r1, #0x0
	adds r0, #0x0C
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bhi _080C9E22
	b _080C9E1E
	.byte 0x00, 0x00
_080C9E00: .4byte 0x02034DA8
_080C9E04:
	adds r0, r1, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C9E22
	adds r0, r1, #0x0
	adds r0, #0x0C
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bls _080C9E22
_080C9E1E:
	movs r0, #0x01
	b _080C9E24
_080C9E22:
	movs r0, #0x00
_080C9E24:
	pop {r1}
	bx r1
.syntax divided

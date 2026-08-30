.syntax unified
	.align 2, 0
	.global func_080CBAB0
	.thumb
	.thumb_func
	.type func_080CBAB0, %function
func_080CBAB0: @ 080CBAB0
	push {r4, lr}
	bl func_080CA67C
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x03
	bl func_080D2D80
	cmp r4, #0x01
	bne _080CBAD0
	ldr r0, _080CBACC @ =0x0000FFFE
	bl func_080C7BCC
	b _080CBB70
_080CBACC: .4byte 0x0000FFFE
_080CBAD0:
	cmp r4, #0x02
	bne _080CBB70
	movs r0, #0x0D
	bl func_0800FDD0
	bl func_080C9910
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CBB6A
	movs r0, #0x03
	bl func_080D2D6C
	bl func_080CBA8C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CBB42
	movs r0, #0x01
	bl func_080D2D94
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CBB08
	movs r0, #0x93
	bl func_080C7B84
	b _080CBB70
_080CBB08:
	movs r0, #0x00
	bl func_080D2D94
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CBB2E
	movs r0, #0x00
	bl func_080D2D6C
	movs r0, #0x01
	bl func_080D2D6C
	movs r0, #0x4D
	bl func_0800FDD0
	movs r0, #0x8F
	bl func_080C7B84
	b _080CBB70
_080CBB2E:
	movs r0, #0x01
	bl func_080D2D6C
	movs r0, #0x4D
	bl func_0800FDD0
	movs r0, #0x91
	bl func_080C7B84
	b _080CBB70
_080CBB42:
	movs r0, #0x00
	bl func_080D2D94
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CBB62
	movs r0, #0x00
	bl func_080D2D6C
	movs r0, #0x4D
	bl func_0800FDD0
	movs r0, #0x90
	bl func_080C7B84
	b _080CBB70
_080CBB62:
	movs r0, #0x92
	bl func_080C7B84
	b _080CBB70
_080CBB6A:
	ldr r0, _080CBB78 @ =0x0000FFFD
	bl func_080C7BCC
_080CBB70:
	adds r0, r4, #0x0
	pop {r4}
	pop {r1}
	bx r1
_080CBB78: .4byte 0x0000FFFD
.syntax divided

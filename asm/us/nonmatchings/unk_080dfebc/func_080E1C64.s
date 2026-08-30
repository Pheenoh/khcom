.syntax unified
	.align 2, 0
	.global func_080E1C64
	.thumb
	.thumb_func
	.type func_080E1C64, %function
func_080E1C64: @ 080E1C64
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _080E1C9A
	ldr r0, _080E1CA0 @ =0x02034F34
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x20]
	lsls r0, r4, #0x02
	ldr r1, _080E1CA4 @ =0x0984D3F8
	adds r0, r0, r1
	ldrb r1, [r0, #0x01]
	lsls r1, r1, #0x02
	ldrb r0, [r0, #0x02]
	lsls r0, r0, #0x06
	adds r1, r1, r0
	strb r4, [r3, #0x05]
	lsls r1, r1, #0x01
	adds r2, r2, r1
	str r2, [r3, #0x1C]
_080E1C9A:
	pop {r4}
	pop {r0}
	bx r0
_080E1CA0: .4byte 0x02034F34
_080E1CA4: .4byte 0x0984D3F8
.syntax divided

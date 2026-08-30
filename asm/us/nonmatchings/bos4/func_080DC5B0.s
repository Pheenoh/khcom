.syntax unified
	.align 2, 0
	.global func_080DC5B0
	.thumb
	.thumb_func
	.type func_080DC5B0, %function
func_080DC5B0: @ 080DC5B0
	push {lr}
	bl func_080DC528
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DC5E0
	ldr r0, _080DC5DC @ =0x02034F0C
	ldr r1, [r0, #0x00]
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080DC5D6
	adds r2, #0x04
	adds r0, r1, r2
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080DC5E0
_080DC5D6:
	movs r0, #0x01
	b _080DC5E2
	.byte 0x00, 0x00
_080DC5DC: .4byte 0x02034F0C
_080DC5E0:
	movs r0, #0x00
_080DC5E2:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

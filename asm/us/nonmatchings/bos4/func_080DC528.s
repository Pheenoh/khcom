.syntax unified
	.align 2, 0
	.global func_080DC528
	.thumb
	.thumb_func
	.type func_080DC528, %function
func_080DC528: @ 080DC528
	ldr r0, _080DC53C @ =0x02034F0C
	ldr r0, [r0, #0x00]
	movs r1, #0xA1
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080DC540
	movs r0, #0x01
	b _080DC542
_080DC53C: .4byte 0x02034F0C
_080DC540:
	movs r0, #0x00
_080DC542:
	bx lr
.syntax divided

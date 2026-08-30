.syntax unified
	.align 2, 0
	.global func_080D1650
	.thumb
	.thumb_func
	.type func_080D1650, %function
func_080D1650: @ 080D1650
	push {lr}
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D169C
	bl func_080C9910
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D169C
	ldr r0, _080D1690 @ =0x0203C40C
	ldrh r1, [r0, #0x00]
	ldr r0, _080D1694 @ =0x000009EB
	cmp r1, r0
	bls _080D169C
	adds r0, #0x9F
	cmp r1, r0
	bhi _080D169C
	ldr r0, _080D1698 @ =0x0203C3F8
	ldrh r1, [r0, #0x00]
	movs r0, #0xA9
	lsls r0, r0, #0x03
	cmp r1, r0
	bhi _080D169C
	subs r0, #0x4F
	cmp r1, r0
	bls _080D169C
	movs r0, #0x01
	b _080D169E
	.byte 0x00, 0x00
_080D1690: .4byte 0x0203C40C
_080D1694: .4byte 0x000009EB
_080D1698: .4byte 0x0203C3F8
_080D169C:
	movs r0, #0x00
_080D169E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

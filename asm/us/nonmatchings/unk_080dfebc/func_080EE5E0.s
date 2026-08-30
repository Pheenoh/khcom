.syntax unified
	.align 2, 0
	.global func_080EE5E0
	.thumb
	.thumb_func
	.type func_080EE5E0, %function
func_080EE5E0: @ 080EE5E0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _080EE5FC @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080EE604
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x06
	ldr r1, _080EE600 @ =0x09963D64
	b _080EE60C
_080EE5FC: .4byte 0x02039BB0
_080EE600: .4byte 0x09963D64
_080EE604:
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x06
	ldr r1, _080EE628 @ =0x09961A64
_080EE60C:
	adds r4, r0, r1
	movs r0, #0x00
	bl func_08005130
	adds r1, r0, #0x0
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r1, r1, r2
	adds r0, r4, #0x0
	bl func_080043B4
	pop {r4}
	pop {r0}
	bx r0
_080EE628: .4byte 0x09961A64
.syntax divided

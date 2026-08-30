.syntax unified
	.align 2, 0
	.global func_080CC488
	.thumb
	.thumb_func
	.type func_080CC488, %function
func_080CC488: @ 080CC488
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _080CC4C0 @ =0x0203C3E4
	ldrh r1, [r0, #0x00]
	movs r0, #0x03
	subs r4, r0, r1
	ldr r0, _080CC4C4 @ =0x0203C3E0
	ldrh r1, [r0, #0x00]
	ldr r0, _080CC4C8 @ =0x000001CD
	cmp r1, r0
	bhi _080CC4B6
	adds r0, r2, #0x0
	movs r1, #0x14
	bl __udivsi3
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080CC4B6
	cmp r4, #0x02
	bgt _080CC4B6
	adds r4, #0x01
_080CC4B6:
	adds r0, r4, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080CC4C0: .4byte 0x0203C3E4
_080CC4C4: .4byte 0x0203C3E0
_080CC4C8: .4byte 0x000001CD
.syntax divided

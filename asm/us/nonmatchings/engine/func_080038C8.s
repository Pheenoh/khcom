.syntax unified
	.align 2, 0
	.global func_080038C8
	.thumb
	.thumb_func
	.type func_080038C8, %function
func_080038C8: @ 080038C8
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl AllocObjTiles
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _080038DE
	movs r0, #0x02
	str r0, [r1, #0x28]
_080038DE:
	adds r0, r1, #0x0
	pop {r1}
	bx r1
.syntax divided

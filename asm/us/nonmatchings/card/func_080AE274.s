.syntax unified
	.align 2, 0
	.global func_080AE274
	.thumb
	.thumb_func
	.type func_080AE274, %function
func_080AE274: @ 080AE274
	push {lr}
	cmp r1, #0x00
	beq _080AE280
	bl func_0800FCD8
	b _080AE284
_080AE280:
	bl func_0800FC90
_080AE284:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080C7BCC
	.thumb
	.thumb_func
	.type func_080C7BCC, %function
func_080C7BCC: @ 080C7BCC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _080C7BF0 @ =0x02034D4C
	strh r2, [r0, #0x00]
	adds r0, r2, #0x3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bhi _080C7BE2
	movs r2, #0x45
_080C7BE2:
	ldr r0, _080C7BF4 @ =0x02034D30
	movs r1, #0x00
	bl func_080A411C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C7BF0: .4byte 0x02034D4C
_080C7BF4: .4byte 0x02034D30
.syntax divided

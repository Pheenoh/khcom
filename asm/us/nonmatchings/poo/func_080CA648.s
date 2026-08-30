.syntax unified
	.align 2, 0
	.global func_080CA648
	.thumb
	.thumb_func
	.type func_080CA648, %function
func_080CA648: @ 080CA648
	push {lr}
	adds r1, r0, #0x0
	ldr r0, [r1, #0x00]
	lsls r0, r0, #0x08
	lsrs r0, r0, #0x10
	ldr r1, [r1, #0x04]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	bl func_080CA36C
	ldr r1, _080CA66C @ =0x000003FF
	ands r1, r0
	ldr r0, _080CA670 @ =0x000003BA
	cmp r1, r0
	bhi _080CA674
	movs r0, #0x00
	b _080CA676
	.byte 0x00, 0x00
_080CA66C: .4byte 0x000003FF
_080CA670: .4byte 0x000003BA
_080CA674:
	movs r0, #0x01
_080CA676:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080DC544
	.thumb
	.thumb_func
	.type func_080DC544, %function
func_080DC544: @ 080DC544
	push {r4, lr}
	movs r4, #0x01
	ldr r0, _080DC554 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x80
	bl func_08000C8C
	b _080DC560
_080DC554: .4byte 0x02039B84
_080DC558:
	adds r0, r1, #0x0
	adds r0, #0xB8
	bl func_08000CD4
_080DC560:
	adds r1, r0, #0x0
	cmp r1, #0x00
	beq _080DC56E
	ldr r0, [r1, #0x00]
	cmp r0, #0x23
	bne _080DC558
	movs r4, #0x00
_080DC56E:
	adds r0, r4, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

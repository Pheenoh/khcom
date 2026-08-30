.syntax unified
	.align 2, 0
	.global func_080E8624
	.thumb
	.thumb_func
	.type func_080E8624, %function
func_080E8624: @ 080E8624
	push {lr}
	ldr r0, _080E863C @ =0x02039BB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080E8636
	ldr r0, _080E8640 @ =0x0203C7B8
	ldr r0, [r0, #0x00]
	bl func_080009C4
_080E8636:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E863C: .4byte 0x02039BB0
_080E8640: .4byte 0x0203C7B8
.syntax divided

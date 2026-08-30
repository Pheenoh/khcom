.syntax unified
	.align 2, 0
	.global func_081075D8
	.thumb
	.thumb_func
	.type func_081075D8, %function
func_081075D8: @ 081075D8
	push {lr}
	ldr r0, _081075F4 @ =0x02035FC4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r1, _081075F8 @ =0x02035FC6
	movs r2, #0x00
	ldsh r1, [r1, r2]
	bl func_081075C0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_081075F4: .4byte 0x02035FC4
_081075F8: .4byte 0x02035FC6
.syntax divided

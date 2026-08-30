.syntax unified
	.align 2, 0
	.global func_08005074
	.thumb
	.thumb_func
	.type func_08005074, %function
func_08005074: @ 08005074
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	ldr r5, _080050A8 @ =0x09ECEB30
	lsls r4, r0, #0x02
	adds r4, r4, r5
	ldr r6, [r4, #0x00]
	ldrh r5, [r6, #0x00]
	ldr r4, _080050AC @ =0x0000FFF3
	ands r4, r5
	lsrs r1, r1, #0x16
	orrs r4, r1
	strh r4, [r6, #0x00]
	ldrh r4, [r6, #0x00]
	ldr r1, _080050B0 @ =0x0000E0FF
	ands r1, r4
	lsrs r2, r2, #0x10
	orrs r1, r2
	strh r1, [r6, #0x00]
	ldr r1, _080050B4 @ =0x030074D0
	adds r0, r0, r1
	strb r3, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080050A8: .4byte 0x09ECEB30
_080050AC: .4byte 0x0000FFF3
_080050B0: .4byte 0x0000E0FF
_080050B4: .4byte 0x030074D0
.syntax divided

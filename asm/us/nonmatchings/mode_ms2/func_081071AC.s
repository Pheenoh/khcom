.syntax unified
	.align 2, 0
	.global func_081071AC
	.thumb
	.thumb_func
	.type func_081071AC, %function
func_081071AC: @ 081071AC
	push {r4, r5, r6, lr}
	bl func_0810718C
	adds r1, r0, #0x0
	ldrh r0, [r1, #0x00]
	cmp r0, #0x1A
	bhi _08107208
	movs r4, #0x00
	movs r2, #0x06
	ldsh r0, [r1, r2]
	ldr r5, _08107200 @ =0x02035FC4
	ldr r6, _08107204 @ =0x02035FC6
	cmp r0, #0x00
	bgt _081071E6
	adds r1, #0x06
_081071CA:
	lsls r0, r4, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	bgt _081071E6
	lsls r0, r0, #0x01
	adds r0, r1, r0
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	ble _081071CA
_081071E6:
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x05
	bl __divsi3
	strh r0, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x05
	bl __modsi3
	strh r0, [r6, #0x00]
	b _08107212
_08107200: .4byte 0x02035FC4
_08107204: .4byte 0x02035FC6
_08107208:
	ldr r0, _08107218 @ =0x02035FC4
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _0810721C @ =0x02035FC6
	strh r1, [r0, #0x00]
_08107212:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08107218: .4byte 0x02035FC4
_0810721C: .4byte 0x02035FC6
.syntax divided

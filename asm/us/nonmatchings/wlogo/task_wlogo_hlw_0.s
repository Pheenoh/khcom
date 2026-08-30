.syntax unified
	.align 2, 0
	.global task_wlogo_hlw_0
	.thumb
	.thumb_func
	.type task_wlogo_hlw_0, %function
task_wlogo_hlw_0: @ 080B5C64
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080B5CA4 @ =0x096FAE04
	movs r0, #0x00
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _080B5CA8 @ =0x096438E4
	movs r2, #0xC0
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080B5CAC @ =0x096BAC64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r4, #0x02]
	strb r1, [r4, #0x00]
	strb r1, [r4, #0x04]
	movs r1, #0x10
	movs r2, #0x00
	bl func_080057A0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B5CA4: .4byte 0x096FAE04
_080B5CA8: .4byte 0x096438E4
_080B5CAC: .4byte 0x096BAC64
.syntax divided
